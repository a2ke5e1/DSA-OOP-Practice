import java.util.Scanner;

enum PokemonType {
    FIRE, WATER, GRASS
}

abstract class Pokemon {

    int hp = 100;
    String name = "";
    PokemonType type;
    
    Pokemon(String name, int hp, PokemonType type) {
        this.name = name;
        this.hp = hp;
        this.type = type;
    }

    abstract void attack1(Pokemon p1);
    abstract void attack2(Pokemon p1);
}

class Charmander extends Pokemon {
    Charmander() {
        super("Charmander", 100, PokemonType.FIRE);
    }

    void attack1(Pokemon p1) {
        System.out.println("Charmander used tackle!");
        p1.hp -= 10;
    }
    void attack2(Pokemon p1) {
        System.out.println("Charmander used ember!");
        p1.hp -= 20;
    }
}

class Squirtle extends Pokemon {
    Squirtle() {
        super("Squirtle", 100, PokemonType.WATER);
    }

    void attack1(Pokemon p1) {
        System.out.println("Squirtle used tackle!");
        p1.hp -= 10;
    }
    void attack2(Pokemon p1) {
        System.out.println("Squirtle used water gun!");
        p1.hp -= 20;
    }
}

class Bulbasaur extends Pokemon {
    Bulbasaur() {
        super("Bulbasaur", 100, PokemonType.GRASS);
    }

    void attack1(Pokemon p1) {
        System.out.println("Bulbasaur used tackle!");
        p1.hp -= 10;
    }
    void attack2(Pokemon p1) {
        System.out.println("Bulbasaur used vine whip!");
        p1.hp -= 20;
    }
}

class Player {

    String name = "";
    Pokemon pokemon;

    Player(String name, Pokemon pokemon) {
        this.name = name;
        this.pokemon = pokemon;
    }

}


class NewGame {

    private static Pokemon getPokemon(int pokemon) {
        switch (pokemon) {
            case 1:
                return new Charmander();
            case 2:
                return new Squirtle();
            case 3:
                return new Bulbasaur();
            default:
                return null;
        }
    }
    

    public static void main(String[] args) {
        System.out.println("Welcome to the Pokemon game!");
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.println("Hello " + name + "!");

        System.out.println("Choose your pokemon: Charmander(1), Squirtle(2), or Bulbasaur(3)");
        int pokemon = scanner.nextInt();
        System.out.println("You choose " + getPokemon(pokemon).name + "!");

        Player player = new Player(name, getPokemon(pokemon));

        System.out.println("Your opponent is choosing a pokemon...");

        int enemyPokemon = (int) (Math.random() * 3) + 1;
        while (enemyPokemon == pokemon) {
            enemyPokemon = (int) (Math.random() * 3) + 1;
        }

        System.out.println("Your opponent choose " + getPokemon(enemyPokemon).name + "!");
        Player enemy = new Player("Enemy", getPokemon(enemyPokemon));
        
        int playerChoice = 0;
        do {

            System.out.println("Choose your attack: 1 or 2");
            playerChoice = scanner.nextInt();

            if (playerChoice == 1) {
                player.pokemon.attack1(enemy.pokemon);
            } else if (playerChoice == 2) {
                player.pokemon.attack2(enemy.pokemon);
            } else {
                System.out.println("Invalid choice!");
            }

            // Enemy's turn
            int enemyChoice = (int) (Math.random() * 2) + 1;
            if (enemyChoice == 1) {
                enemy.pokemon.attack1(player.pokemon);
            } else if (enemyChoice == 2) {
                enemy.pokemon.attack2(player.pokemon);
            }

            System.out.println(player.pokemon.name + " HP: " + player.pokemon.hp);
            System.out.println(enemy.pokemon.name + " HP: " + enemy.pokemon.hp);




        } while (player.pokemon.hp > 0 && enemy.pokemon.hp > 0);

        if (player.pokemon.hp > 0) {
            System.out.println("You win!");
        } else {
            System.out.println("You lose!");
        }
    
    }
}


