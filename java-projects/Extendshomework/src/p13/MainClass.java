package p13;

class A
{
    int methodOfA(int i)
    {
        i /= 10;

        return i;
    }
}

class B extends A
{
    int methodOfB(int i)
    {
        i *= 20;

        return methodOfA(i);
    }
}

public class MainClass
{
    public static void main(String[] args)
    {
        B b = new B();

        System.out.println(b.methodOfB(100));
    }
}

//200