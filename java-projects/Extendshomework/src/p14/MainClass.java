package p14;

class One
{
    int x = 2121;
}

class Two extends One
{
    int x = 1212;

    {
        System.out.println(x);
    }
}

public class MainClass
{
    public static void main(String[] args)
    {
        Two two = new Two();
    }
}

//1212