import org.junit.*;

public class NotTriangleTest {
    Triangle triangle = new Triangle(0, 0, 0);

    @Test
    public void sumTwoEquals1(){
        triangle.setEdgesLength(10,5,5);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void sumTwoEquals2(){
        triangle.setEdgesLength(5,10,5);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void sumTwoEquals3(){
        triangle.setEdgesLength(5,5,10);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void sumTwoLesser1(){
        triangle.setEdgesLength(5,4,10);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void sumTwoLesser2(){
        triangle.setEdgesLength(4,10,5);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void sumTwoLesser3(){
        triangle.setEdgesLength(10,5,4);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
}