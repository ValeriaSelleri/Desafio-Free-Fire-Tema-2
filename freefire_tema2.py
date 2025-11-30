# Versão Python do Desafio Free Fire - Tema 2 (simples)

class Item:
    def __init__(self, id_, nome, tipo, poder):
        self.id = id_
        self.nome = nome
        self.tipo = tipo
        self.poder = poder

class Jogador:
    def __init__(self, id_, nome):
        self.id = id_
        self.nome = nome
        self.vida = 100
        self.itens = []

def carregar_itens_exemplo():
    return [
        Item(1, "Rifle M4", "arma", 35),
        Item(2, "Shotgun", "arma", 40),
        Item(3, "Kit Medico", "kit", 0),
        Item(4, "Colete Nivel 2", "colete", 0),
        Item(5, "Sniper", "arma", 50),
    ]

def main():
    itens = carregar_itens_exemplo()
    qtd = int(input("Quantos jogadores? (1-8): "))
    jogadores = []
    for i in range(qtd):
        nome = input(f"Nome do jogador {i+1}: ").strip() or f"Jogador{i+1}"
        jogadores.append(Jogador(i+1, nome))
    # distribuir 1 item por jogador
    for i, j in enumerate(jogadores):
        j.itens.append(itens[i % len(itens)])
    print("\n--- Estado inicial ---")
    for j in jogadores:
        print(f"{j.id} - {j.nome} | Vida: {j.vida} | Itens: {len(j.itens)}")
        for it in j.itens:
            print(f"   - {it.nome} ({it.tipo}, poder {it.poder})")

if __name__ == "__main__":
    main()
