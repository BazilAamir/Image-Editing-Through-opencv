#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <conio.h>
using namespace std;
using namespace cv;


class cv1 {
private:
    int x;
    Mat image;
public:
    void create() {
        string x;
        cout << "Enter the pathway of your image file in proper format e.g (C:\\Users\\pc\\Desktop\\lion.jpeg)" << endl;
        cin >> x;
        image = imread(x);

        
        if (image.empty()) {
            cerr << "Error: Could not open or find the image." << endl;

        };


    }
    cv1() {
        create();
    }

    void resizing() {
        Mat newimage;
        cout << "Current Image Size: " << image.size() << endl;
        cout << "Resize to( values between 0-1): ";
        float newsize;
        cin >> newsize;
        resize(image, newimage, Size(), newsize, newsize);
        image = newimage;
    }
    void cropping() {
        int xaxis, yaxis, length, height;
        cout << "amount of cutoff from x axis: ";
        cin >> xaxis;
        cout << "amount of cutoff from y axis: ";
        cin >> yaxis;
        cout << "Enter length: ";
        cin >> length;
        cout << "height ";
        cin >> height;
        Rect roi(xaxis, yaxis, length, height);
        image = image(roi);

    }
    void rotation() {
        float angle;
        float scale = 1.0;
        cout << "Enter angle of rotation: ";
        cin >> angle;
        Point2f centre(image.cols / 2.0, image.rows / 2.0);
        Mat angled = getRotationMatrix2D(centre, angle, scale);
        Mat newimage;
        warpAffine(image, newimage, angled, image.size());
        image = newimage;
    }
    void blur() {
        int kSize;
        cout << "Enter blurryness value (0-15 normal input): ";
        cin >> kSize;
        GaussianBlur(image, image, Size(kSize, kSize), 0);

    }
    void sharpen() {
        float degree;
        cout << "Enter degree of sharpening: ";
        cin >> degree;
        Mat img = (Mat_<float>(3, 3) << 0.0f, -1.0f, 0.0f, -1.0f, degree, -1.0f, 0.0f, -1.0f, 0.0f);
        filter2D(image, image, image.depth(), img);
    }
    void greyscale() {
        cvtColor(image, image, COLOR_BGR2GRAY);
    }
    void brightness() {
        Mat newimage;
        float x;
        cout << endl << "Increase Brightness by(_x): ";
        cin >> x;
        image.convertTo(newimage, -1, x, 50);
    }
    void contrast() {
        Mat newimage;
        float x;
        cout << endl << "Increase Brightness by(_x): ";
        cin >> x;
        image.convertTo(newimage, -1, 50, x);
    }
    void display() {
        namedWindow("My Image", WINDOW_NORMAL);


        imshow("My Image", image);


        waitKey(0);
    }
    void save() {
        string name, loc;
        int op;
        cout << endl << "Enter name of the image: ";
        cin >> name;
        cout << "Enter destination of saved image(Type 0 to save in same place) (Also add \\ at end): ";
        cin >> loc;
        if (loc == "0")
        {
            loc = "";
        }
        cout << "which format would you like to save in: " << endl;
        cout << "enter 1 for JPEG" << endl;
        cout << "enter 2 for PNG" << endl;
        cout << "press 3 for BMP" << endl;
        cin >> op;
        if (op == 1)
            imwrite(loc + name + ".jpg", image);
        else if (op == 2)
            imwrite(loc + name + ".png", image);
        else imwrite(loc + name + ".bmp", image);
    }

};

int main() {
    int x = 10;
    cv1 a;
    while (x != 48) {
        cout << "which format would you like to save in: " << endl;
        cout << "enter 1 for resize" << endl;
        cout << "enter 2 for cropping image" << endl;
        cout << "enter 3 for rotating image" << endl;
        cout << "enter 4 for blur filter" << endl;
        cout << "enter 5 for sharpening of image" << endl;
        cout << "enter 6 for greyscale filter" << endl;
        cout << "enter 7 for brightness ajustment " << endl;
        cout << "enter 8 for contrast adjustment" << endl;
        cout << "enter 0 to save image and exit" << endl;
        x = _getch();
        switch (x) {
        case 49:
            a.resizing();
            a.display();
            break;
        case 50:
            a.cropping();
            a.display();
            break;
        case 51:
            a.rotation();
            a.display();
            break;
        case 52:
            a.blur();
            a.display();
            break;
        case 53:
            a.sharpen();
            a.display();
            break;
        case 54:
            a.greyscale();
            a.display();
            break;
        case 55:
            a.brightness();
            a.display();
            break;
        case 56:
            a.contrast();
            a.display();
            break;
        }
    }
    a.save();

    destroyAllWindows();

    return 0;
}