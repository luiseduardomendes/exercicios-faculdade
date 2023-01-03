public class Cat_interface implements Animal_interface{
    @Override
    public void speak() {
        System.out.println("Meow!");
    }

    @Override
    public void move(Vector d) {
        pos.sum(d);
    }
}
