import java.util.HashSet;
import java.util.Objects;

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int[] conner = {
                Integer.MAX_VALUE,
                Integer.MAX_VALUE,
                Integer.MIN_VALUE,
                Integer.MIN_VALUE
        };
        HashSet<Pair> set = new HashSet<>();
        int area = 0;
        for (int[] rect : rectangles) {
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            for (int i = 0; i < 2; i++) {
                conner[i] = Integer.min(conner[i], rect[i]);
            }
            for (int i = 2; i < 4; i++) {
                conner[i] = Integer.max(conner[i], rect[i]);
            }
            for (int i = 0; i < 4; i += 2) {
                for (int j = 1; j < 4; j += 2) {
                    Pair k = new Pair(rect[i], rect[j]);
                    if (set.contains(k)) {
                        set.remove(k);
                    } else {
                        set.add(k);
                    }
                }
            }
        }
        if (set.size() != 4) {
            return false;
        }
        for (int i = 0; i < 4; i += 2) {
            for (int j = 1; j < 4; j += 2) {
                Pair k = new Pair(conner[i], conner[j]);
                if (!set.contains(k)) {
                    return false;
                }
            }
        }
        return area == (conner[2] - conner[0]) * (conner[3] - conner[1]);
    }

    class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x &&
                    y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}

public class Main {
    static int[][] r = {
            {1, 1, 3, 3},
            {3, 1, 4, 2},
            {3, 2, 4, 4},
            {1, 3, 2, 4},
            {2, 3, 3, 4}
    };

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isRectangleCover(r));
    }
}
