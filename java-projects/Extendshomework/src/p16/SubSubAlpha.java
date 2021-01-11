package p16;

class Alpha
{
    static String s = " ";
    protected Alpha()
    {
        s += "alpha ";
    }
}
class SubAlpha extends Alpha
{
    private SubAlpha()
    {
        s += "sub ";
    }
}

public class SubSubAlpha extends Alpha
{
    private SubSubAlpha()
    {
        s += "subsub ";
    }
    public static void main(String[] args)
    {
        new SubSubAlpha();
        System.out.println(s);//alpha subsub
//        new SubAlpha();
    }
}

//错误:private 访问控制