package CakePrac;

public class ReadyMadeCake extends Cake {
    private int quantity;

    public ReadyMadeCake(int quantity, double perPrice) {
        this.quantity = quantity;
        setPrice(perPrice);
    }

    public int getQuantity() {
        return quantity;
    }

    @Override
    public double price() {
        return getPrice() * quantity;
    }
}
