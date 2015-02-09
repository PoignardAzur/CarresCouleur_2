

#ifndef HEADER_FORMAT_TABLEAU_TILES
#define HEADER_FORMAT_TABLEAU_TILES


template <typename T = char>
class TileArray
{
    public :

    TileArray() {}
    TileArray(const std::vector<T>& tableau, int nhauteur, int nlargeur);
    TileArray(const T& objet, int nhauteur, int nlargeur);
    void set(const std::vector<T>& tableau, int nhauteur, int nlargeur);
    void set(const T& objet, int nhauteur, int nlargeur);

    int width() const;
    int height() const;


    T& element(int x, int y);
    const T& element(int x, int y) const;
/*
    T& operator()(int x, int y);
    const T& operator()(int x, int y) const;
*/
    const std::vector<T>& array() const;

    private :

    int m_hauteur;
    int m_largeur;
    std::vector<T> m_tableau;
};








template <typename T>
TileArray<T>::TileArray(const std::vector<T>& tableau, int nhauteur, int nlargeur)
{
    set(tableau, nhauteur, nlargeur);
}


template <typename T>
TileArray<T>::TileArray(const T& objet, int nhauteur, int nlargeur)
{
    set(std::vector<T>(nhauteur * nlargeur, objet));
}


template <typename T>
void TileArray<T>::set(const T& objet, int nhauteur, int nlargeur)
{
    set(std::vector<T>(nhauteur * nlargeur, objet));
}


template <typename T>
void TileArray<T>::set(const std::vector<T>& tableau, int nhauteur, int nlargeur)
{
    m_hauteur = nhauteur;
    m_largeur = nlargeur;

    if (tableau.size() != nhauteur * nlargeur)
    throw "La taille du tableau ne correspond pas à ses dimensions données.";

/// else
    m_tableau = tableau;
}







template <typename T>
T& TileArray<T>::element(int x, int y)
{
    return m_tableau[x + y * m_largeur];
}



template <typename T>
const T& TileArray<T>::element(int x, int y) const
{
    return element(x, y);
}

/*
template <typename T>
T& TileArray<T>::operator()(int x, int y)
{
    return element(x, y);
}


template <typename T>
const T& TileArray<T>::operator()(int x, int y) const
{
    return element(x, y);
}
*/




template <typename T>
int TileArray<T>::height() const
{
    return m_hauteur;
}


template <typename T>
int TileArray<T>::width() const
{
    return m_largeur;
}


template <typename T>
const std::vector<T>& TileArray<T>::array() const
{
    return m_tableau;
}


#endif

