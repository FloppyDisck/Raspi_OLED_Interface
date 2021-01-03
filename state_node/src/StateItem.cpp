#include "statemod/StateItem.hpp"

template<typename T>
StateItem<T>::StateItem(const char *name, Node *previous, T minValue, T maxValue, T stepQnty, T initState) : Node(name, previous),
min(minValue), max(maxValue), step(stepQnty), state(initState) {}

template<typename T>
Node *StateItem<T>::input(int input) {
    //Up arrow
    if (input==JOY_U) {
        state = max;
    }
        //Down arrow
    else if (input==JOY_D) {
        state = min;
    }
        //Left arrow
    else if (input==JOY_L) {
        //Goes left or negative
        state -= step;
        if (state < min) {
            state = min;
        }
    }
        //Right arrow
    else if (input==JOY_R) {
        //Goes right or positive
        state += step;
        if (state > max) {
            state = max;
        }
    }

    else if (input==JOY_M) {
        return previous_;
    }

    return this;
}

template<typename T>
T StateItem<T>::getState() {
    return state;
}

template<typename T>
void StateItem<T>::draw() {
    int mid = OLED_X_MAXPIXEL/2 - (nameLen_ * font->Width)/2;
    drawItem(false, mid, 1, 0, 0, font, name_, nameLen_);


    std::string valStr = std::to_string(state);
    const char* valC = valStr.c_str();
    int valN = valStr.size();
    mid = OLED_X_MAXPIXEL/2 - (valN * font->Width)/2;
    drawItem(false, mid, 1 + (2*itemSize_), 0, 0, font, valC, valN);
    OLED_Display();
    OLED_Clear(0x00);
}

//Instantiate the template classes
template class StateItem<int>;
template class StateItem<float>;
template class StateItem<double>;

