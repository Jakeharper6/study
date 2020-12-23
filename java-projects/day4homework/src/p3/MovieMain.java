package p3;

public class MovieMain {

    // 电影名：除暴  评分(平均)：8.9  评分次数：10000
    // 电影名：金刚川  评分(平均)：9.1  评分次数：10000

    public static void main(String[] args) {
        Movie m1 = new Movie("除暴", 0.0, 0);
        Movie m2 = new Movie("金刚川", 0.0, 0);

        System.out.println(m1.getInfo());
        // 给m1评分9.0
        m1.score(9.0);
        System.out.println(m1.getInfo());
        m1.score(8.0);
        System.out.println(m1.getInfo());

        m2.score(10);
        m2.score(10f);
        m2.score('A');
        System.out.println(m2.getInfo());

    }
}