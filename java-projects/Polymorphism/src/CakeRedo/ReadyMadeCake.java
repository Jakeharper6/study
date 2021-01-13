package CakeRedo;

public class ReadyMadeCake extends Cake{
    private int quantity;

    public ReadyMadeCake(int quantity,double price) {
        this.quantity = quantity;
        setPrice(price);
    }

    @Override
    public double calPrice() {
        return getPrice() * quantity;
    }

    public int getQuantity() {
        return quantity;
    }

    @Override
    public void amount() {
        System.out.println(quantity);
    }
}
