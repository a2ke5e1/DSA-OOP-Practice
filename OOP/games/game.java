//pokemon
import java.util.*;

public class pokemon {
    void charmander() {
        System.out.println("Charmander");
        int hp = 100;

        void attack1() {
            String name = "tackle";
            int damage = 10;
        }
        void attack2() {
            String name = "ember";
            int damage = 20;
        }
        
    }
    void squirtle() {
        int hp = 100;
        System.out.println("Squirtle");
        void attack1() {
            String name = "tackle";
            int damage = 10;
        }
        void attack2() {
            String name = "water gun";
            int damage = 20;
        }
    }
    void bulbasaur() {
        int hp = 100;
        System.out.println("Bulbasaur");
        void attack1() {
            String name = "tackle";
            int damage = 10;
        }
        void attack2() {
            String name = "vine whip";
            int damage = 20;
        }
    }
}

public class player extends pokemon {
    void player() {
        System.out.println("Enter your name:");
        String player = Scanner.nextLine(System.in);
        System.out.println("Hello " + player + "!");

        System.out.println("Choose your pokemon: Charmander, Squirtle, or Bulbasaur");
        String pokemon = Scanner.nextLine(System.in);
        System.out.println("You chose " + pokemon + "!");
        if (pokemon == "Charmander") {
            charmander();
        }
        else if (pokemon == "Squirtle") {
            squirtle();
        }
        else if (pokemon == "Bulbasaur") {
            bulbasaur();
        }
    }
}

public class enemy extends pokemon {
    while(pokemon != 0) {
        int pokemon = Math.random() * 3;
        if (pokemon == 0) {
            charmander();
        }
        else if (pokemon == 1) {
            squirtle();
        }
        else if (pokemon == 2) {
            bulbasaur();
        }
    }
}

public class game{
    public static void main(String[] args) {
        player player = new player();
        enemy enemy = new enemy();
        random random = new random();

        System.out.println("Welcome to the Pokemon game!");
        player.player();
        enemy.enemy();
        random.random();

        System.out.println("You encountered a " + enemy.pokemon + "!");
        System.out.println("What will you do?");
        System.out.println("1. Attack\n2. Run");
        int choice = Scanner.nextInt(System.in);
        do{
            switch (choice) {
                case 1:
                    System.out.println("Choose your attack:");
                    System.out.println("1. " + player.attack1.name + "\n2. " + player.attack2.name);
                    int attack = Scanner.nextInt(System.in);

                    switch (attack) {
                        case 1:
                            System.out.println("You used " + player.attack1.name + "!");
                            enemy.hp -= player.attack1.damage;
                            break;
                        case 2:
                            System.out.println("You used " + player.attack2.name + "!");
                            enemy.hp -= player.attack2.damage;
                            break;
                        default:
                            System.out.println("Invalid input");
                            break;
                    }while(true);
                    int enemyAttack = Math.random() * 2;
                    switch (enemyAttack) {
                        case 1:
                            System.out.println("The " + enemy.pokemon + " used " + enemy.attack1.name + "!");
                            player.hp -= enemy.attack1.damage;
                            break;
                        case 2:
                            System.out.println("The " + enemy.pokemon + " used " + enemy.attack2.name + "!");
                            player.hp -= enemy.attack2.damage;
                            break;
                        default:
                            System.out.println("Invalid input");
                            break;
                    
                    break;
                case 2:
                    System.out.println("You ran away!");
                    break;

                default:
                    System.out.println("Invalid input");
                    break;
            }while(true);
            if(enemy.hp <= 0) {
                System.out.println("You defeated the " + enemy.pokemon + "!");
                break;
            }else if(player.hp <= 0) {
                System.out.println("You lost!");
                break;
            }
        }while(enemy.hp > 0);
        System.out.println("Game over!");

    }
}