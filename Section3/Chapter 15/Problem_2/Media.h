#ifndef MURACH_MEDIA_H
#define MURACH_MEDIA_H

#include <string>
#include "Product.h"

class Media : public Product{ //inherits the Product class
    protected:
        std::string format;       
    public:
        Media(std::string name = "", double price = 0.0, int discountPct = 0, std::string formatParam = "") : 
        Product(name, price, discountPct){
            format = formatParam;
        }
};
#endif //MURACH_MEDIA_H