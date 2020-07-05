#ifndef POSITION_H
#define POSITION_H

/**
 * \class Position
 * \brief Klasa służąca do przechodywania punktów współrzędnych na osi X i Y
 */
class Position
{
public:
    /**
     * \brief Konstruktor z przypisaniem punktu współrzędnych
     */
    Position(int X,int Y);
    /**
     * \brief Konstruktor domyślny
     */
    Position();
private:
    int iX;
    int iY;
public:
    /**
     * \brief Funckcja ustawiajaca wartość współrzędnej X
     *
     * \param[in] X
     */
    void set_X(int X);
    /**
     * \brief Funckcja ustawiajaca wartość współrzędnej Y
     *
     * \param[in] Y
     */
    void set_Y(int Y);
    /**
     * \brief Funckcja zwracająca wartość współrzędnej X
     *
     * \param[out] iX
     */
    int get_X();
    /**
     * \brief Funckcja zwracająca wartość współrzędnej Y
     *
     * \param[out] iY
     */
    int get_Y();
};

#endif // POSITION_H
