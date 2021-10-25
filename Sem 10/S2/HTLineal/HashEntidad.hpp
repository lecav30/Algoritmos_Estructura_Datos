#ifndef __HASHENTIDAD_HPP__
#define __HASHENTIDAD_HPP__

template <typename T>
class HashEntidad
{
private:
	int key;
	T value;

public:
	HashEntidad(int key, T value)
	{
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	T getValue() { return value; }
	void setValue(T v) { value = v; }
};

#endif // !__HASHENTIDAD_HPP__
