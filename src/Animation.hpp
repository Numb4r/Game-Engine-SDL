#ifndef ANIMATION_HPP
#define ANIMATION_HPP
class Animation
{
private:
    /* data */
public:
    unsigned int index;
    unsigned int numFrames;
    unsigned int animationSpeed;
    Animation(/* args */);
    Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
    ~Animation() {}
};
#endif