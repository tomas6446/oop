#include <iostream>
#include <vector>

class Langas
{
private:
    float height, width;
    static int windowsCreated;
public:
    Langas()
    {
        width = 0;
        height = 0;
    }

    Langas(float width, float height)
    {
        this->width = width;
        this->height = height;
        windowsCreated++;
        printf("Window created. count: %d\n", windowsCreated);
    }

    ~Langas()
    {
        windowsCreated--;
        printf("Door deconstructed. count: %d\n", windowsCreated);
    }

    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }
};

int Langas::windowsCreated = 0;

class Durys
{
private:
    float height, width;
    static int doorsCreated;
public:
    Durys()
    {
        width = 0;
        height = 0;
    }

    Durys(float width, float height)
    {
        this->width = width;
        this->height = height;
        doorsCreated++;
        printf("Door created. count: %d\n", doorsCreated);
    }

    ~Durys()
    {
        doorsCreated--;
        printf("Door deconstructed. count: %d\n", doorsCreated);
    }

    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }
};

int Durys::doorsCreated = 0;

class Kambarys
{
private:
    float width, height, length, area, plinthWidth;
    std::vector<Durys *> door;
    std::vector<Langas *> window;
public:
    Kambarys()
    {
        width = 0;
        height = 0;
        length = 0;
    }

    Kambarys(float width, float height, float length)
    {
        this->width = width;
        this->height = height;
        this->length = length;
    }

    ~Kambarys()
    {
        for (auto i: door)
        {
            delete[] i;
        }
        for (auto i: window)
        {
            delete[] i;
        }
        door.clear();
        window.clear();
    }

    void addDoor(class Durys *d)
    {
        door.push_back(d);
    }

    void addWindow(class Langas *w)
    {
        window.push_back(w);
    }

    void calcWallArea()
    {
        float doorArea = 0;
        for (auto &i: door) // get sum of all door areas
        {
            doorArea += i->getHeight() * i->getWidth();
        }

        float windowArea = 0;
        for (auto &i: window) // get sum of all window area
        {
            doorArea += i->getHeight() * i->getWidth();
        }

        area = 2 * ((height * width) + (height * length) + (width * length)) - (windowArea + doorArea);
    }

    void calcPlinthPerimeter()
    {
        float doorWidth = 0;
        for (auto &i: door)
        {
            doorWidth += i->getWidth();
        }

        plinthWidth = (2 * width + 2 * length) - doorWidth;
    }

    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }

    float getLength()
    {
        return length;
    }

    float getArea()
    {
        return area;
    }

    float getPlinth()
    {
        return plinthWidth;
    }
};

int main()
{
    Langas *window = new Langas[2];
    window[0] = {100, 50};
    window[1] = {120, 50};
    Durys *door = new Durys[2];
    door[0] = {50, 200};
    door[1] = {60, 220};

    Kambarys kambarys(220, 260, 300);
    kambarys.addDoor(door);
    kambarys.addWindow(window);

    kambarys.calcWallArea();
    kambarys.calcPlinthPerimeter();
    printf("Sienu Plotas: %0.1f\nGrindjuosciu ilgis: %0.1f\n", kambarys.getArea(), kambarys.getPlinth());


    return 0;
}
