import java.util.*;

class Block {
    List<Point> points;
    int[] level;
    int leftIndex = 101;
    int bottomIndex = 0;
    int colSize;
    int blockNumber;

    public Block() {
        points = new ArrayList<>();
        level = new int[3];
    }
}

class Point {
    int y;
    int x;

    public Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int MAX_DIRECTIONS = 4;

    public static int MAX_ROW;
    public static int MAX_COL;

    public Block block;
    public int[][] staticBoard;
    public int[][] mainBoard;
    List<Block> removableBlocks = new ArrayList<>();

    public int solution(int[][] board) {
        int answer = 0;
        staticBoard = this.copy(board);
        mainBoard = this.copy(board);
        MAX_ROW = board.length;
        MAX_COL = board[0].length;

        for (int row = 0; row < MAX_ROW; ++row) {
            for (int col = 0; col < MAX_COL; ++col) {
                int boardNumber = staticBoard[row][col];
                if (boardNumber == 0) continue;
                block = new Block();
                block.blockNumber = boardNumber;
                makeBlock(row, col, boardNumber, 0);
                block.colSize = Math.max(Math.max(block.level[0], block.level[1]), block.level[2]);
                if (this.isAvailableRemove()) {
                    removableBlocks.add(block);
                }
            }
        }
        answer = removeBlocks();
        System.out.println(answer);
        return answer;
    }

    private int removeBlocks() {
        int countOfRemove = 0;
        while (true) {
            int beforeRemoveSize = removableBlocks.size();
            for (int blockIdx = 0; blockIdx < removableBlocks.size(); ++blockIdx) {
                Block block = removableBlocks.get(blockIdx);
                for (Point point : block.points) {
                    mainBoard[point.y][point.x] = 0;
                }

                if (validRemove(block)) {
                    removableBlocks.remove(block);
                    blockIdx--;
                    countOfRemove++;
                } else {
                    for (Point point : block.points) {
                        mainBoard[point.y][point.x] = block.blockNumber;
                    }
                }

            }
            int afterRemoveSize = removableBlocks.size();
            if (afterRemoveSize == 0 || beforeRemoveSize == afterRemoveSize) {
                break;
            }
        }
        return countOfRemove;
    }

    private boolean validRemove(Block block) {
        int row = block.bottomIndex;
        int leftIndex = block.leftIndex;
        for (; row >= 0; row--) {
            if (block.colSize == 2) {
                if (mainBoard[row][leftIndex] != 0 || mainBoard[row][leftIndex + 1] != 0) {
                    return false;
                }
            } else {
                if (mainBoard[row][leftIndex] != 0
                        || mainBoard[row][leftIndex + 1] != 0
                        || mainBoard[row][leftIndex + 2] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isAvailableRemove() {
        int[] level = block.level;
        if (level[2] == 0) {
            level[2] = 9999;
        }
        for (int i = 0; i < level.length; ++i) {
            level[i] = (level[i] == 0) ? 9999 : level[i];
        }
        if (level[0] <= level[1] && level[1] <= level[2]) {
            return true;
        }
        return false;
    }

    private void storeLevel(int level) {
        block.level[level]++;
    }

    public void makeBlock(int y, int x, int blockNumber, int level) {
        block.points.add(new Point(y, x));
        block.leftIndex = Math.min(block.leftIndex, x);
        block.bottomIndex = Math.max(block.bottomIndex, y);
        storeLevel(level);
        staticBoard[y][x] = 0;
        for (int next = 0; next < MAX_DIRECTIONS; ++next) {
            int nextY = y + dy[next];
            int nextX = x + dx[next];
            if (nextY < 0 || nextY >= MAX_ROW || nextX < 0 || nextX >= MAX_COL) {
                continue;
            } else if (staticBoard[nextY][nextX] != blockNumber) {
                continue;
            }
            if (next == 1) {
                makeBlock(nextY, nextX, blockNumber, level + 1);
            } else {
                makeBlock(nextY, nextX, blockNumber, level);
            }
        }
    }

    private int[][] copy(int[][] input) {
        int[][] target = new int[input.length][];
        for (int i = 0; i < input.length; i++) {
            target[i] = Arrays.copyOf(input[i], input[i].length);
        }
        return target;
    }
}

public class lth {
    public static void main(String... args) {
        Solution solution = new Solution();
        int[][] board =
                {
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                };
        solution.solution(board);
    }
}
