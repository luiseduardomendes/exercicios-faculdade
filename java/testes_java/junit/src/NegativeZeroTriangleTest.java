import org.junit.*;

public class NegativeZeroTriangleTest {
    Triangle triangle = new Triangle(0, 0, 0);

    @Test
    public void zeroValues1(){
        triangle.setEdgesLength(4,10,0);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void zeroValues2(){
        triangle.setEdgesLength(4,0,0);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void zeroValues3(){
        triangle.setEdgesLength(0,0,0);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void negativeValues1(){
        triangle.setEdgesLength(-4,10,10);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void negativeValues2(){
        triangle.setEdgesLength(4,-10,10);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
    @Test
    public void negativeValues3(){
        triangle.setEdgesLength(4,10,-10);
        Assert.assertEquals(triangle.classification(), "NotTriangle");
    }
}

