import java.util.ArrayList;
import java.util.Iterator;

public class App {
    public static void main(String[] args) throws Exception {
        
        testAnimalsAbstract();

    }

    public static void testAnimalsAbstract(){
        ArrayList<Animal_abstract> animals = new ArrayList<Animal_abstract>(); 
        
        animals.add(new Cat_abstract());
        animals.add(new Dog_abstract());
        
        Iterator<Animal_abstract> it = animals.iterator();

        while(it.hasNext()){
            it.next().speak();
        }
    }

    public static void testAnimals(){
        ArrayList<Animal> animals = new ArrayList<Animal>(); 
        
        animals.add(new Cat());
        animals.add(new Dog());
        
        Iterator<Animal> it = animals.iterator();

        while(it.hasNext()){
            it.next().speak();
        }
    }
}
