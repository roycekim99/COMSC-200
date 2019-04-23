
class Rectangle {
private:
    double width;
    double length;
public:
    Rectangle(double w = 0, double l = 0) {
        if (w < 0) {
            throw NegativeWidth(w);
        }
        else {
            width = w;
        }
        length = l;
    }

    void setWidth(double w) {
        if (w < 0) {
            throw NegativeWidth(w);
        }
        else {
            width = w;
        }
    }

    void setLength(double l) {
        length = l;
    }

    class NegativeWidth {
    private:
        double val;
    public:
        NegativeWidth(double v) {
            val = v;
        }
        
        double getValue() {
            return val;
        }
    };
};



int main() {
    Rectangle myRectangle;
    try {
        myRectangle.setWidth(2);
        myRectangle.setLength(2);
    }
    catch(Rectangle::NegativeWidth e){
        std::cout << "error:" << e.getValue();
    }
}