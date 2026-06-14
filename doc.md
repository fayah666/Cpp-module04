## 1. Définitions rapides

| Terme | Signification en C++ |
|------|----------------------|
| **Classe abstraite** | Une classe qui possède au moins **une fonction
virtuelle pure** (`= 0`). Elle ne peut pas être instanciée. |
| **Interface** (dans le sens de Java/C#) | En C++ il n’existe pas de
mot‑clé `interface`. On **implémente** une interface en créant **une
classe abstraite « pure »** : toutes ses fonctions sont pures, il n’y a
pas (ou très peu) d’attributs de données. |
| **Fonction virtuelle pure** | `virtual Retour foo(Param) = 0;` → la
classe qui la déclare devient abstraite. |
| **Polymorphisme d’objet** | Le mécanisme qui permet d’appeler, via un
pointeur/référence de type base, la version la plus dérivée d’une fonction
virtuelle. |

---

## 2. Pourquoi les utiliser ?

| Situation | Solution avec classe abstraite / interface |
|-----------|--------------------------------------------|
| **Définir un contrat** (ex. : « tout objet qui se dessine doit fournir
`draw()` ») | Créez une classe avec une fonction virtuelle pure `draw()`.
|
| **Séparer l’implémentation de la spécification** | Les modules qui
utilisent le contrat ne connaissent pas les détails de l’implémentation. |
| **Permettre plusieurs implémentations différentes** (ex. : rendu OpenGL
vs DirectX) | Vous dérivez plusieurs classes concrètes de la même
interface. |
| **Faciliter les tests unitaires / le mock** | Vous pouvez substituer une
classe « fake » qui implémente l’interface mais ne fait rien. |

---

## 3. Syntaxe de base

```cpp
// 1️⃣ Une classe abstraite (au moins une fonction pure)
class Shape {
public:
    // Méthode abstraite
    virtual double area() const = 0;     // = 0 → pure virtual
    virtual void draw() const = 0;

    // Vous pouvez aussi avoir des méthodes concrètes
    void translate(double dx, double dy) {
        x_ += dx; y_ += dy;
    }

    // Des membres de donnée sont autorisés (mais pas obligatoires)
protected:
    double x_ = 0.0, y_ = 0.0;   // position du centre, par exemple
    // Destructor virtuel obligatoire si vous allez supprimer via un
pointeur base
    virtual ~Shape() = default;
};
```

### 3.1. Une « interface » pure (style Java)

```cpp
// 2️⃣ Une « interface » : aucune donnée, toutes les méthodes sont pures
class ISerializable {
public:
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string&) = 0;

    // Un destructeur virtuel même si on ne veut rien de spécial
    virtual ~ISerializable() = default;
};
```

> **Règle d’or** : quand **toutes** les fonctions sont pures et la classe
ne possède **pas** d’état (pas d’attributs non‑statiques), on l’appelle
typiquement « interface ».

---

## 4. Implémentation concrète

```cpp
class Circle : public Shape, public ISerializable {
public:
    explicit Circle(double radius) : radius_(radius) {}

    // ---- Implémentation de Shape ----
    double area() const override { return 3.1415926535 * radius_ *
radius_; }
    void draw() const override {
        std::cout << "Dessine un cercle de rayon " << radius_ << "\n";
    }

    // ---- Implémentation de ISerializable ----
    std::string serialize() const override {
        return "Circle:" + std::to_string(radius_);
    }
    void deserialize(const std::string& s) override {
        // très simple, on attend "Circle:<val>"
        auto pos = s.find(':');
        radius_ = std::stod(s.substr(pos + 1));
    }

private:
    double radius_;
};
```

### Points à remarquer

* `override` : obligatoire (ou fortement recommandé) pour vérifier que
vous redéfinissez bien une fonction virtuelle de la base.
* Vous pouvez **hériter de plusieurs interfaces** (multiple inheritance)
tant que les bases sont *pures* → pas de problème de “diamond” (diamant)
car il n’y a pas d’état partagé.
* Le destructeur de chaque base est virtuel (`virtual ~Base() =
default;`). Sans cela, `delete pBase;` ne libérerait pas correctement la
partie dérivée.

---

## 5. Utilisation (polymorphisme)

```cpp
void renderAll(const std::vector<Shape*>& objects) {
    for (const Shape* s : objects)
        s->draw();               // appel dynamique → la version de la
classe dérivée
}

int main() {
    Circle c1(5.0);
    // Vous pourriez avoir d’autres formes : Rectangle, Triangle, ...

    std::vector<Shape*> scene = { &c1 };
    renderAll(scene);  // => Dessine un cercle de rayon 5

    // Exemple d’interface :
    ISerializable* ser = &c1;
    std::cout << ser->serialize() << '\n'; // Circle:5.000000
}
```

---

## 6. Différence *pratique* entre “classe abstraite” et “interface”

| Aspect | Classe abstraite (C++) | Interface (style Java) |
|--------|----------------------|------------------------|
| **Etat (données membres)** | Autorisé (protected ou private) | Aucun (ou
uniquement static const) |
| **Constructeur** | Peut en avoir (utile pour initialiser l’état) |
Normalement pas (pas besoin d’initialiser quoi que ce soit) |
| **Héritage multiple** | Possible, mais attention aux conflits d’état
(diamant) | Habituellement multiple, sans problème d’état |
| **But principal** | Fournir à la fois un *contrat* **et** une partie
d’implémentation commune | Uni‑seulement un *contrat* (ensemble de
méthodes à implémenter) |
| **Nomination** | Souvent `BaseX`, `AbstractX` | Souvent `IXxx` ou `IXXX`
(préfixe `I`) pour rappeler le style interface |

> En pratique, **l’interface pure** est une sous‑catégorie de **classe
abstraite**.

---

## 7. Bonnes pratiques (check‑list)

| ✅ | Règle |
|----|-------|
| 1 | **Toujours** déclarer le destructeur `virtual` (ou `= default`) dans
une classe polymorphe. |
| 2 | Utilisez le suffixe `= 0` **uniquement** dans la déclaration, jamais
dans la définition (pas besoin de corps). |
| 3 | Marquez chaque redéfinition avec `override` (et éventuellement
`final` si vous ne voulez plus que quelqu’un la surcharge). |
| 4 | Si votre « interface » ne doit contenir aucun état, **déclarez‑la**
`struct` plutôt que `class` (par convention, les membres sont publics). |
| 5 | Préférez **l’héritage public** de l’interface (`class Foo : public
IBar`) ; l’héritage privé rend les fonctions invisibles à l’extérieur. |
| 6 | Évitez les **castings** (`dynamic_cast`) inutiles. Si vous avez
besoin de savoir le type exact, repensez votre conception (peut‑être le
pattern Visitor). |
| 7 | Pour les gros projets, **documentez** le contrat (pré‑et
post‑conditions) dans les commentaires d’une interface. |
| 8 | **Ne mettez pas** d’implémentation dans une fonction pure (`=0`). Si
vous avez besoin d’une implémentation par défaut, fournissez‑la **dans la
classe de base** (non‑pure) et rendez‑la `virtual`. |
| 9 | Si vous avez besoin de *templates* plutôt que du polymorphisme
d’objet, envisagez le **CRTP** ou les **concepts C++20**. |
|10 | Lors de la compilation, activez `-Wall -Wextra -Wpedantic` pour être
alerté sur les fonctions virtuelles non‑surchargées, les destructeurs
manquants, etc. |

---

## 8. Concepts C++20 (alternative moderne)

Depuis C++20, vous pouvez exprimer un **contrat** sans créer de classe
abstraite grâce aux *concepts* :

```cpp
template<class T>
concept Drawable = requires(const T& obj) {
    { obj.draw() } -> std::same_as<void>;
};

template<Drawable D>
void render(const D& d) {
    d.draw();               // compile‑time polymorphism
}
```

*Avantages* : pas de surcharge virtuelle → pas de v‑table, résolutions à
la compilation.
*Inconvénients* : ne fonctionne pas si vous avez besoin d’un conteneur
hétérogène (`std::vector<std::unique_ptr<Shape>>` reste nécessaire).

---

## 9. Exercices à faire

| # | Description | Indications |
|---|--------------|--------------|
| 1 | **Création d’une interface** `ICloneable` avec `clone()` retournant
`std::unique_ptr<ICloneable>`. Implémentez‑la dans `Circle` et
`Rectangle`. | Utilisez `std::make_unique<Circle>(*this)` dans `clone()`.
|
| 2 | **Classe abstraite** `Animal` avec `virtual void speak() const =
0;`. Ajoutez une méthode non‑pure `void info() const` qui affiche le nom
de l’animal. Implémentez `Dog` et `Cat`. | `info()` utilise un attribut
protégé `std::string name_;`. |
| 3 | **Polymorphisme multiple** : créez deux interfaces `IFlyable`
(`fly()`) et `ISwimmable` (`swim()`). Implémentez `Duck` qui hérite des
deux et fournit les méthodes. Testez via `std::vector<IFlyable*>` et
`std::vector<ISwimmable*>`. | Aucun état partagé, seulement les méthodes.
|
| 4 | **Conversion au concept** : écrivez un concept `Serializable` qui
requiert `std::string serialize() const`. Faites en sorte que `Circle` et
`Rectangle` le satisfassent sans hériter d’une classe. | Comparez l’usage
du concept vs de l’interface. |
| 5 | **Gestion correcte du destructeur** : créez une classe `Base` avec
un destructeur **non** virtuel, dérivez `Derived`. Allouez dynamiquement
`Derived` via `Base* p = new Derived;` et `delete p;`. Observez le
comportement (le destructeur de `Derived` n’est pas appelé). Corrigez en
ajoutant `virtual ~Base()`. | Utilisez `valgrind` ou l’option
`-fsanitize=address` pour vérifier les fuites. |

---

## 10. Ressources complémentaires

| Type | Lien / Référence |
|------|------------------|
| **Livre** | *“C++ Primer (5e)”* – chap. 13 (polymorphisme, classes
abstraites) |
| **Documentation officielle** | cppreference.com – pages **[virtual
functions](https://en.cppreference.com/w/cpp/language/virtual)** et
**[abstract
classes](https://en.cppreference.com/w/cpp/language/abstract_class)** |
| **Tutoriels vidéo** | *CppCon 2014 – “Polymorphism in C++”* (YouTube) |
| **Article** | *“Designing Interfaces in Modern C++”* – en ligne sur
**herbsutter.com** (article de Herb Sutter, 2022) |
| **Exemple complet** | GitHub repo `github.com/akrzemi1/CppInterfaceDemo`
(code source illustrant plusieurs interfaces, concepts, tests unitaires) |

---

## 11. Récapitulatif en 5 points

1. **Classe abstraite** = au moins une fonction virtuelle pure →
impossible à instancier.
2. **Interface pure** = classe abstraite *sans état* (tout `=0`). On
l’utilise comme contrat.
3. `override` + `virtual ~Base() = default` = bonnes pratiques de
sécurité.
4. Héritage multiple d’interfaces est sûr tant qu’il n’y a pas d’état
partagé.
5. C++20 offre les *concepts* comme alternative compile‑time aux
interfaces run‑time.

---

### Besoin d’un exemple supplémentaire ?
N’hésitez pas à préciser un domaine (graphisme, simulation, système
embarqué…) et je vous fournirai un petit projet complet adapté. Bon
codage ! 🚀
