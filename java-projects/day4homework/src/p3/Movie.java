package p3;

public class Movie {

    // 电影名：除暴  评分(平均)：8.9  评分次数：10000
    // 电影名：金刚川  评分(平均)：9.1  评分次数：10000

    String name;
    double averageScore;
    int scoreTotalTimes;

    public Movie() {
    }

    public Movie(String name, double averageScore, int scoreTotalTimes) {
        this.name = name;
        this.averageScore = averageScore;
        this.scoreTotalTimes = scoreTotalTimes;
    }

    /**
     * 如果传入的评分是<0或者>10输出不合法的评分，否则输出平均分
     *
     * @param score 评分
     */
    public void score(double score) {
        if (score < 0 || score > 10){
            System.out.println("评分不合法");
        }else {
            // 总分  次数
            // (总分 + 评分)  /  (次数 + 1)
            // (（旧的平均分 * 旧的次数）（原始总分） + 评分 ) / (旧次数 + 1)

            // 总分 / 次数
            // 原始总分
            double originTotalScore = averageScore * scoreTotalTimes;
            // scoreTotalTimes++;

            // averageScore = (originTotalScore + score) / scoreTotalTimes;

            // 先计算++结果，并对scoreTotalTimes赋值后，取出最后的结果参与除法运算
            averageScore = (originTotalScore + score) / ++scoreTotalTimes;

            // 先取出值，然后对scoreTotalTimes+1赋值，然后将之前取出的值参与除法运算
            // averageScore = (originTotalScore + score) / scoreTotalTimes++; // 结果错误
        }
    }

    /**
     * 输出电影信息
     *
     * @return 电影名：xxx ,评分：9.1 ,评分次数：10000
     */
    public String getInfo() {
        return "电影名：" + name + ",评分：" + averageScore + ",评分次数:" + scoreTotalTimes;
    }
}
