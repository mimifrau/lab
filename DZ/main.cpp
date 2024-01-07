#include "for_this_damn_carriage_to_work/global.h"
#include "for_this_damn_carriage_to_work/function.h"

using namespace sf;

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(N * w, M * w), "Tetris!");
    Texture t, backgroung;
    t.loadFromFile("tiles.jpg");
    backgroung.loadFromFile("background.jpg");
    Sprite tiles(t);
    Sprite background(backgroung);

    int dx = 0, colorNum = 1;
    bool rotate = false;
    float timer = 0, delay = 0.3;
    Clock clock;
    bool ad = true;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Up)
                    rotate = true;
                else if (event.key.code == Keyboard::Right)
                    dx = 1;
                else if (event.key.code == Keyboard::Left)
                    dx = -1;
        }


        if (Keyboard::isKeyPressed(Keyboard::Down))
            delay = 0.05;

        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
            a[i].x += dx;
        }

        if (!check()) {
            for (int i = 0; i < 4; i++)
                a[i] = b[i];
        }

        if (rotate) {
            Point p = a[1];
            for (int i = 0; i < 4; i++) {
                int x = a[i].y - p.y;
                int y = a[i].x - p.x;

                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }

            if (!check()) {
                for (int i = 0; i < 4; i++)
                    a[i] = b[i];
            }
        }

        if (timer > delay) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].y += 1;
            }

            if (!check()) {
                for (int i = 0; i < 4; i++)
                    field[b[i].y][b[i].x] = colorNum;
                colorNum = 1 + rand() % 7;
                int n = rand() % 7;
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            }

            timer = 0;
        }

        if (ad) {
            int n = rand() % 7;
            if (a[0].x == 0)
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            ad = false;
        }

        int k = M - 1;
        for (int i = M - 1; i > 0; i--) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (field[i][j])
                    count++;
                field[k][j] = field[i][j];
            }
            if (count < N)
                k--;
        }

        dx = 0;
        rotate = false;
        delay = 0.3;

        window.clear(Color::White);
        window.draw(background);

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 0)
                    continue;
                tiles.setTextureRect(IntRect(field[i][j] * w, 0, w, w));
                tiles.setPosition(j * w, i * w);
                window.draw(tiles);
            }

        for (int i = 0; i < 4; i++) {
            tiles.setTextureRect(IntRect(colorNum * w, 0, w, w));
            tiles.setPosition(a[i].x * w, a[i].y * w);
            window.draw(tiles);
        }

        window.display();
    }

    return 0;
}
