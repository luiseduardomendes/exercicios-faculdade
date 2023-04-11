import org.junit.*;

public class ClassificationTriangleTest {
    Triangle triangle = new Triangle(0, 0, 0);

    @Test
    public void equilateral(){
        triangle.setEdgesLength(10,10,10);
        Assert.assertEquals(triangle.classification(), "Equilateral");
    }    
    @Test
    public void isosceles1(){
        triangle.setEdgesLength(5,10,10);
        Assert.assertEquals(triangle.classification(), "Isosceles");
    }
    @Test
    public void isosceles2(){
        triangle.setEdgesLength(10,5,10);
        Assert.assertEquals(triangle.classification(), "Isosceles");
    }
    @Test
    public void isosceles3(){
        triangle.setEdgesLength(10,10,5);
        Assert.assertEquals(triangle.classification(), "Isosceles");
    }
    @Test
    public void scalene(){
        triangle.setEdgesLength(8,10,5);
        Assert.assertEquals(triangle.classification(), "Scalene");
    }
    
    
}
