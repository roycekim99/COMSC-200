///**********************************************************************************
/// Description: Contains LandTrack Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 17, 2019
/// Status : Complete 
///***********************************************************************************

class LandTract {
private:
    FeetInches width, length;
    // private helper if necessary
public:
    LandTract() {}
    LandTract(FeetInches a, FeetInches b) : width(a), length(b) {}

    // bare minimum compiler scilencer, modify accordingly
    FeetInches getWidth() { return width; }
	FeetInches getLength() { return length; }
	FeetInches getArea() { 
        double w, l;
        w = width;
        l = length;
        return FeetInches(w*l);
    } 
	// all the rest of necessary public member methods, go here
};