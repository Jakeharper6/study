package p30;

class ClassOne {

    static int i = 111;

    int j = 222;

    {
        i = i++ - ++j;
    }
}

class ClassTwo extends ClassOne {

    {
        i = -113;
        j = i-- + --j;
    }
}

class Main {

    public static void main(String args[]) {
        ClassTwo clsTwo = new ClassTwo();
        System.out.println(clsTwo.i);
        System.out.println(clsTwo.j);
    }
}

//-114
//109