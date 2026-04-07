class Robot {
    int w, h, x, y, dir;
    int cycle;
    boolean moved;

    public Robot(int width, int height) { 
        this.w = width;
        this.h = height;
        this.x = 0;
        this.y = 0;
        this.dir = 0; // 0=East, 1=North, 2=West, 3=South
        this.cycle = 2 * (width + height) - 4;
        this.moved = false;
    }

    public void step(int num) {
        num %= cycle;
        if (num == 0 && moved) {
            num = cycle;
        }

        moved = true;

        for (int i = 0; i < num; i++) {
            if (dir == 0) { // East
                if (x + 1 < w) {
                    x++;
                } else {
                    dir = 1;
                    y++;
                }
            } else if (dir == 1) { // North
                if (y + 1 < h) {
                    y++;
                } else {
                    dir = 2;
                    x--;
                }
            } else if (dir == 2) { // West
                if (x - 1 >= 0) {
                    x--;
                } else {
                    dir = 3;
                    y--;
                }
            } else { // South
                if (y - 1 >= 0) {
                    y--;
                } else {
                    dir = 0;
                    x++;
                }
            }
        }
    }

    public int[] getPos() {
        return new int[]{x, y};
    }

    public String getDir() {
        String[] dirs = {"East", "North", "West", "South"};
        return dirs[dir];
    }
}
