package p10;

class X {
    int m = 1111;

    {
        m = m++;
        System.out.println(m);
    }
}

class Y extends X {
    {
        System.out.println(methodOfY());
    }

    int methodOfY()    {
//        1111+1109
        return m-- + --m;
    }
}

public class MainClass
{
    public static void main(String[] args)
    {
        Y y = new Y();
    }
}

//1111
//2220
