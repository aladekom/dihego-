import subprocess
import os
import sys
import tkinter as tk
from tkinter import messagebox, ttk

def rodar_ordenacao():
    criterio = str(var_criterio.get()) # "1" para Titulo, "2" para Preco
    ordem = str(var_ordem.get())       # "1" para Crescente, "2" para Decrescente

    # Determina o nome do executavel compilado em C
    executavel = "ordenador.exe" if os.name == 'nt' else "./ordenador"

    if not os.path.exists(executavel) and not os.path.exists("ordenador.exe"):
        messagebox.showerror(
            "Erro no Executável", 
            "O programa 'ordenador.exe' não foi encontrado na pasta!\n\n"
            "Abra o terminal e compile com:\ngcc main.c -o ordenador"
        )
        return

    if not os.path.exists("catalogo.txt"):
        messagebox.showerror(
            "Erro de Ficheiro", 
            "O ficheiro 'catalogo.txt' não existe na pasta do projeto."
        )
        return

    try:
        # Chama o ficheiro binario compilado em C
        cmd = [os.path.abspath(executavel), criterio, ordem]
        resultado = subprocess.run(cmd, capture_output=True, text=True, check=True)

        # Limpa os dados antigos da tabela
        for row in tree.get_children():
            tree.delete(row)

        # Le o ficheiro de saida gerado pelo C
        if os.path.exists("catalogo_ordenado.txt"):
            with open("catalogo_ordenado.txt", "r", encoding="utf-8", errors="ignore") as f:
                for linha in f:
                    linha = linha.strip()
                    if linha:
                        partes = linha.split(";")
                        if len(partes) == 2:
                            titulo, preco = partes
                            try:
                                valor_float = float(preco)
                                tree.insert("", "end", values=(titulo, f"R$ {valor_float:.2f}"))
                            except ValueError:
                                tree.insert("", "end", values=(titulo, preco))
        else:
            messagebox.showerror("Erro", "O ficheiro 'catalogo_ordenado.txt' não foi gerado pelo programa em C.")

    except subprocess.CalledProcessError as e:
        messagebox.showerror("Erro na Execução do C", f"Erro ao executar o programa C:\n{e.stderr}")
    except Exception as e:
        messagebox.showerror("Erro de Aplicação", str(e))

# Interface Gráfica Tkinter
root = tk.Tk()
root.title("Catálogo de Livros - C + Python")
root.geometry("520x460")

tk.Label(root, text="Catálogo de Livros", font=("Arial", 16, "bold")).pack(pady=10)

# Opções de Seleção
frame_opcoes = tk.Frame(root)
frame_opcoes.pack(pady=5)

var_criterio = tk.IntVar(value=1)
var_ordem = tk.IntVar(value=1)

frame_crit = tk.LabelFrame(frame_opcoes, text=" Ordenar Por ", padx=10, pady=5)
frame_crit.pack(side=tk.LEFT, padx=10)
tk.Radiobutton(frame_crit, text="Título", variable=var_criterio, value=1).pack(anchor=tk.W)
tk.Radiobutton(frame_crit, text="Preço", variable=var_criterio, value=2).pack(anchor=tk.W)

frame_ord = tk.LabelFrame(frame_opcoes, text=" Ordem ", padx=10, pady=5)
frame_ord.pack(side=tk.LEFT, padx=10)
tk.Radiobutton(frame_ord, text="Crescente", variable=var_ordem, value=1).pack(anchor=tk.W)
tk.Radiobutton(frame_ord, text="Decrescente", variable=var_ordem, value=2).pack(anchor=tk.W)

# Botão para invocar o C
btn_ordenar = tk.Button(
    root, 
    text="Ordenar Livros (Executar C)", 
    command=rodar_ordenacao, 
    bg="#2196F3", 
    fg="white", 
    font=("Arial", 11, "bold"),
    padx=10,
    pady=5
)
btn_ordenar.pack(pady=15)

# Tabela para Exibição
columns = ("titulo", "preco")
tree = ttk.Treeview(root, columns=columns, show="headings", height=8)
tree.heading("titulo", text="Título do Livro")
tree.heading("preco", text="Preço")
tree.column("titulo", width=330)
tree.column("preco", width=110, anchor="center")
tree.pack(pady=10)

root.mainloop()