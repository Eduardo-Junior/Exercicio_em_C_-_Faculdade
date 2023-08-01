import java.util.Scanner;

public class Exercicio1$22 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Valor do produto: ");
        double valor = Double.parseDouble(scan.nextLine());

        valor *= .91;

        System.out.printf("\nPreco de venda com 9%% de desconto: %.2f", valor);

        scan.close();
    }
}
