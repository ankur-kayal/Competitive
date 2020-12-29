import java.io.*;
import java.util.*;

class A {
    int add(int i , int j) {
        return i + j;
    }
}

public class Test extends A {
    public static void main(String[] args) {
        short s = 9;
        System.out.println(add(s,6));
    }
}