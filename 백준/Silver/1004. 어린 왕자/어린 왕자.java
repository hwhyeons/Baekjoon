import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


class Planet {
    int cx,cy,r;
    public Planet(int cx, int cy, int r) {
        this.cx = cx;
        this.cy = cy;
        this.r = r;
    }
}

public class Main {
    public static void main(String args[]) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        final int testCase = Integer.parseInt(br.readLine());
        for (int i = 0; i < testCase; i++) {
            var list = new ArrayList<Planet>();
            var tk = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(tk.nextToken());
            int y1 = Integer.parseInt(tk.nextToken());
            int x2 = Integer.parseInt(tk.nextToken());
            int y2 = Integer.parseInt(tk.nextToken());
            int planetCount = Integer.parseInt(br.readLine());
            for (int j = 0; j < planetCount; j++) {
                tk = new StringTokenizer(br.readLine());
                int cx = Integer.parseInt(tk.nextToken());
                int cy = Integer.parseInt(tk.nextToken());
                int r = Integer.parseInt(tk.nextToken());
                Planet p = new Planet(cx,cy,r);
                list.add(p);
            }
            long innerCount = list.stream().filter(p->{
                if ((p.cx - x1)*(p.cx - x1) + (p.cy - y1)*(p.cy - y1) < p.r*p.r) {
                    if ((p.cx - x2)*(p.cx - x2) + (p.cy - y2)*(p.cy - y2) > p.r*p.r) {
                        return true;
                    } else return false;
                } else {
                    return false;
                }
            }).count();
            long outerCount = list.stream().filter(p->{
                if ((p.cx - x1)*(p.cx - x1) + (p.cy - y1)*(p.cy - y1) > p.r*p.r) {
                    if ((p.cx - x2)*(p.cx - x2) + (p.cy - y2)*(p.cy - y2) < p.r*p.r) {
                        return true;
                    } else return false;
                } else {
                    return false;
                }
            }).count();
            System.out.println(innerCount+outerCount);
        }
    }
}

