// Use mouse draw an closed outline
// and press any key to paint
boolean[][] screenPixel;
final int WIDTH = 100;
final int HEIGHT = 120;

void setup() {
  size(WIDTH, HEIGHT);
  screenPixel = new boolean[WIDTH][HEIGHT];
  smooth();
}

void draw() {
  background(255);
  for (int i =0; i<WIDTH; i++) {
    for (int j = 0; j<HEIGHT; j++) {
      if (screenPixel[i][j]) {
        point(i, j);
      }
    }
  }
  if (mousePressed) {
    int x = min(WIDTH-1, mouseX);
    x = max(0, x);
    int y = min(HEIGHT-1, mouseY);
    y = max(0, y);
    screenPixel[x][y]=true;
  }
}

void keyReleased() {
  paint(mouseX, mouseY);
}

void paint(int x, int y) {
  if (x<0 || y<0 || x >=WIDTH || y >=HEIGHT) return;
  if (screenPixel[x][y]) {
    return;
  } else {
    screenPixel[x][y]=true;
    paint(x-1, y);
    paint(x+1, y);
    paint(x, y-1);
    paint(x, y+1);
  }
}

