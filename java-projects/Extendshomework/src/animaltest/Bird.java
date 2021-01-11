package animaltest;

public class Bird extends Animal{
    public Bird(int age, double weight) {
        super(age, weight);
    }

    public void fly(){
        System.out.println("I can fly.");
    }
}
