class Shape{
public:
    virtual void draw()=0;
};

class Circle: public Shape{
public:
    void draw(){
        cout<<"Drawing circle"<<endl;
    }
};

class Square: public Shape{
public:
    void draw(){
        cout<<"Drawing square"<<endl;
    }
};

class Rectangle: public Shape{
public:
    void draw(){
        cout<<"Drawing rectangle"<<endl;
    }
};

class ShapeMaker{
    Shape* circle;
    Shape* square;
    Shape* rectangle;
    
public:
    ShapeMaker(){
        circle = new Circle();
        square = new Square();
        rectangle = new Rectangle();
    }
    
    void drawCircle(){
        circle->draw();
    }
    
    void drawSquare(){
        square->draw();
    }
    
    void drawRectangle(){
        rectangle->draw();
    }
};


int main() {
    ShapeMaker *shapeMaker = new ShapeMaker();
    shapeMaker->drawCircle();
    shapeMaker->drawSquare();
    shapeMaker->drawRectangle();
}
