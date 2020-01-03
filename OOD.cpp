/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-03 14:25:20
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-03 15:17:30
 * @Description: Demo for .
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ImageType
{
  GIF,
  JPEG  
};

class ImageReader
{

};

class GIFReader: public ImageReader
{

};

class JPEGReader: public ImageReader
{

};

//工厂模式
class ImageReaderFactory
{
public:
    static ImageReader *ImageReaderFactoryMethod(ImageType imageType)
    {
        ImageReader *product = nullptr;
        switch(imageType)
        {
            case GIF:
                product=new GIFReader();
            case JPEG:
                product = new JPEGReader();
        }

        return product;
    }
};


int main(int argc, char* argv[])
{
    
    return 1;
}

