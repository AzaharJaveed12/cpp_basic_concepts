/*
Problem 6 — Image Cache

Scenario:
    Design an image cache system.
        loadImage("logo.png")

    If the image is already loaded and still alive → return existing one.
        Otherwise → load from disk.

Requirements:

    Class:
        ImageCache

Internal storage should map:
    image name -> cached object

Constraints:
    Images should not remain in memory forever
    If no one uses an image anymore, cache should allow it to be freed
*/

#include <iostream>
#include <memory>
#include <map>

class Image {
private:
    std::string imageName;
    int imageData;
public:
    Image(std::string imageName):
        imageName{std::move(imageName)} {
            imageData = imageName.size() +1000;
        }

    const int getImage() const {return imageData; }
};

class Imagecache {
private:
    std::map<std::string , std::weak_ptr<Image>> cache;
public:
    std::shared_ptr<Image> loadImage(const std::string& imageName) {
        auto it = cache.find(imageName);
    
        if(it != cache.end() && !it->second.expired()) {
            if(auto sp = it->second.lock()) {
                std::cout <<"[ImageCache] : returning from cache - " << imageName <<"\n";
                return sp; 
            }
        }
        
        std::cout <<"[ImageCache] : created newone - " << imageName <<"\n";
        auto sp = std::make_shared<Image>(imageName);
        cache[imageName] = sp;
        return sp; // after this returns sp loose its scope so its refrence count becomes decreased.
    }
};

int main() {
    Imagecache cache;
    auto img1 = cache.loadImage("logo.png");
    auto img2 = cache.loadImage("logo.png");
     {
        auto img3 = cache.loadImage("4.png");
        auto img4 = cache.loadImage("4.png");
     }
     auto img5 = cache.loadImage("4.png");

    return 0;
}
