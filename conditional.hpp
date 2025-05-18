#ifndef CONDITIONAL_CLASS
#define CONDITIONAL_CLASS
#include <type_traits>
#include <variant>

template<typename StoreType, bool SaveValue>
class Conditional{
private:
    using conditional_type = std::conditional_t<SaveValue, StoreType, std::monostate>;
    conditional_type stored_value;

    template<typename InT, typename StoreRef>
    inline void sign_value(const InT& a, StoreRef& ref) noexcept{
    }
    
    inline void sign_value(const StoreType& a, StoreType& ref) noexcept{
        ref = a;
    }

    template<typename InT>
    inline StoreType get_value(const InT& a){
        return {};
    }

    inline StoreType get_value(const StoreType& a){
        return stored_value;
    }

public:
    static constexpr bool save_value = SaveValue;

    Conditional() = default;
    ~Conditional() = default;

    inline Conditional& operator= (const StoreType& a){
        sign_value(a, this->stored_value);
        return *this;
    }

    inline operator StoreType(){
        return get_value(this->stored_value);
    }

    inline StoreType value(){
        return get_value(this->stored_value);
    }

};

#endif