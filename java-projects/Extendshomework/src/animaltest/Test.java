package animaltest;

public class Test {
    public static void main(String[] args) {
        Fish fish = new Fish(5,10.0);
        System.out.println(fish.output());
        fish.swim();

        Bird bird = new Bird(2,4);
        System.out.println(bird.output());
        bird.fly();
    }
}
