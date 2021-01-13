package CakeRedo;

public class OrderCake extends Cake{
    private double weightInKG;

    public OrderCake(double weightInKG,double price) {
        this.weightInKG = weightInKG;
        setPrice(price);
    }

    @Override
    public double calPrice() {
        return getPrice() * weightInKG;
    }

    @Override
    public void amount() {
        System.out.println(weightInKG);
    }
}
