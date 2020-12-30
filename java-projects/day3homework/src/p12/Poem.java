package p12;

public class Poem {
    String poemName;
    int wordCount;
    Author author;

    public Poem(String poemName, int wordCount, Author author) {
        this.poemName = poemName;
        this.wordCount = wordCount;
        this.author = author;
    }

    public void printDetail(){
        System.out.println("诗名：" + this.poemName + "，字数：" + this.wordCount + "，作者：" + this.author.name + "，作者朝代：" + this.author.dynasty + "，作者性别：" + this.author.gender);
    }

    public static void main(String[] args) {
        Author a1 = new Author("李白","唐代","男");

        Poem p1 = new Poem("静夜思",20,a1);

        p1.printDetail();
    }
}
