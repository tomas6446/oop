#include <iostream>
#include <vector>

class ObjectSize
{
private:
    float height = 0, width = 0;

public:
    void setHeight(float h)
    {
        height = h;
    }

    void setWidth(float w)
    {
        width = w;
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

class Langas : public ObjectSize
{
};

class Durys : public ObjectSize
{
};

class Kambarys
{
private:
    float width, height, length, area, plinthWidth;
    std::vector<Durys> door;
    std::vector<Langas> window;
public:
    void setHeight(float h)
    {
        height = h;
    }

    void setWidth(float w)
    {
        width = w;
    }

    void setLength(float a)
    {
        length = a;
    }

    void addDoor(class Durys d)
    {
        door.push_back(d);
    }

    void addWindow(class Langas w)
    {
        window.push_back(w);
    }

    void calcWallArea()
    {
        float doorArea = 0;
        for (auto &i: door) // get sum of all door areas
        {
            doorArea += i.getHeight() * i.getWidth();
        }

        float windowArea = 0;
        for (auto &i: window) // get sum of all window area
        {
            doorArea += i.getHeight() * i.getWidth();
        }

        area = ((2 * (height * width) + 2 * (height * length) + 2 * (width * length))) - (windowArea + doorArea);
    }

    void calcPlinthPerimeter()
    {
        float doorWidth = 0;
        for (auto &i: door)
        {
            doorWidth += i.getWidth();
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
    Langas langas1;
    langas1.setWidth(200);
    langas1.setHeight(150);

    Langas langas2;
    langas2.setWidth(100);
    langas2.setHeight(50);

    Durys durys;
    durys.setWidth(50);
    durys.setHeight(200);

    Kambarys kambarys;
    kambarys.setHeight(220);
    kambarys.setWidth(260);
    kambarys.setLength(300);
    kambarys.addDoor(durys);
    kambarys.addWindow(langas1);
    kambarys.addWindow(langas2);

    kambarys.calcWallArea();
    kambarys.calcPlinthPerimeter();
    printf("Sienu Plotas: %0.1f\nGrindjuosciu ilgis: %0.1f\n", kambarys.getArea(), kambarys.getPlinth());
    return 0;
}
