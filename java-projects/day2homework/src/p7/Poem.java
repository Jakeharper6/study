package p7;
//        诗名：静夜思，字数：20，作者：李白，作者朝代：唐代，作者性别：男

public class Poem {
    String poemName;
    int wordCount;
    Author author;

    public static void main(String[] args) {
        Author a1 = new Author();
        a1.name = "李白";
        a1.dynasty = "唐代";
        a1.gender = "男";

        Poem p1 = new Poem();
        p1.poemName = "静夜思";
        p1.wordCount = 20;
        p1.author = a1;

        System.out.println("诗名：" + p1.poemName + "，字数：" + p1.wordCount + "，作者：" + p1.author.name + "，作者朝代：" + p1.author.dynasty + "，作者性别：" + p1.author.gender);
    }
}
