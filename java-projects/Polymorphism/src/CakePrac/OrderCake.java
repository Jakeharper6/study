package CakePrac;

public class OrderCake extends Cake {
    private double weightInKG;

    public OrderCake(double weightInKG,double perPrice) {
        this.weightInKG = weightInKG;
        setPrice(perPrice);
    }

    @Override
    public double price() {
        return getPrice() * weightInKG;
    }
}
