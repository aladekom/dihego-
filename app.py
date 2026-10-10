import subprocess
import os
import platform
import tkinter as tk
from tkinter import messagebox, scrolledtext

class AppLivrosC:
    def __init__(self, root):
        self.root = root
        self.root.title("Gerenciador de Livros - Backend C")
        self.root.geometry("720x540")
        self.root.config(bg="#f4f4f9")

        # Compila o C automaticamente ao iniciar
        self.compilar_c()

        # Título da Interface
        lbl_titulo = tk.Label(
            root, 
            text="Biblioteca Digital (Backend em C)", 
            font=("Arial", 14, "bold"), 
            bg="#f4f4f9", 
            fg="#333333"
        )
        lbl_titulo.pack(pady=10)

        # Frame de Botões de Controle
        frame_botoes = tk.Frame(root, bg="#f4f4f9")
        frame_botoes.pack(pady=10)

        # Botão Inicial (Desorganizado)
        self.btn_original = tk.Button(
            frame_botoes, text="📂 Lista Original (Desorganizada)", bg="#6c757d", fg="white",
            font=("Arial", 10, "bold"), padx=10, pady=5,
            command=lambda: self.executar_backend("original", "0")
        )
        self.btn_original.grid(row=0, column=0, columnspan=3, pady=5, sticky="ew")

        # Botões Título
        lbl_t = tk.Label(frame_botoes, text="Título:", bg="#f4f4f9", font=("Arial", 10, "bold"))
        lbl_t.grid(row=1, column=0, sticky="w", padx=5, pady=5)
        
        self.btn_tit_cres = tk.Button(
            frame_botoes, text="⬆️ Crescente (A-Z)", bg="#2b580c", fg="white",
            font=("Arial", 9), command=lambda: self.executar_backend("titulo", "1")
        )
        self.btn_tit_cres.grid(row=1, column=1, padx=5, pady=5)

        self.btn_tit_dec = tk.Button(
            frame_botoes, text="⬇️ Decrescente (Z-A)", bg="#856404", fg="white",
            font=("Arial", 9), command=lambda: self.executar_backend("titulo", "0")
        )
        self.btn_tit_dec.grid(row=1, column=2, padx=5, pady=5)

        # Botões Preço
        lbl_p = tk.Label(frame_botoes, text="Preço:", bg="#f4f4f9", font=("Arial", 10, "bold"))
        lbl_p.grid(row=2, column=0, sticky="w", padx=5, pady=5)

        self.btn_preco_cres = tk.Button(
            frame_botoes, text="⬆️ Menor ➔ Maior", bg="#1d3557", fg="white",
            font=("Arial", 9), command=lambda: self.executar_backend("preco", "1")
        )
        self.btn_preco_cres.grid(row=2, column=1, padx=5, pady=5)

        self.btn_preco_dec = tk.Button(
            frame_botoes, text="⬇️ Maior ➔ Menor", bg="#d90429", fg="white",
            font=("Arial", 9), command=lambda: self.executar_backend("preco", "0")
        )
        self.btn_preco_dec.grid(row=2, column=2, padx=5, pady=5)

        # Caixa de texto para exibir a saída do C
        self.txt_output = scrolledtext.ScrolledText(
            root, width=82, height=16, font=("Courier New", 10),
            bg="#ffffff", fg="#333333"
        )
        self.txt_output.pack(pady=10, padx=15)

        # Carrega a lista desorganizada logo na abertura
        self.executar_backend("original", "0")

    def compilar_c(self):
        c_file = "main.c"
        if not os.path.exists(c_file):
            messagebox.showerror("Erro", f"O arquivo '{c_file}' não foi encontrado!")
            return
        
        is_windows = platform.system() == "Windows"
        compilador_output = "programa.exe" if is_windows else "programa"

        # Remove o binário antigo se existir para forçar nova compilação limpa
        if os.path.exists(compilador_output):
            try:
                os.remove(compilador_output)
            except:
                pass

        cmd_compilacao = ["gcc", c_file, "-o", compilador_output]
        resultado = subprocess.run(cmd_compilacao, capture_output=True, text=True)

        if resultado.returncode != 0:
            messagebox.showerror("Erro de Compilação", f"Erro no GCC:\n{resultado.stderr}")

    def executar_backend(self, criterio, tipo):
        is_windows = platform.system() == "Windows"
        exe_path = "programa.exe" if is_windows else "./programa"

        try:
            cmd = [exe_path, criterio, str(tipo)]
            resultado = subprocess.run(cmd, capture_output=True, text=True)

            if resultado.returncode == 0:
                self.txt_output.delete("1.0", tk.END)
                self.txt_output.insert(tk.END, resultado.stdout)
            else:
                messagebox.showerror("Erro", f"Erro ao executar o binário:\n{resultado.stderr}")
        except Exception as e:
            messagebox.showerror("Erro Crítico", str(e))

if __name__ == "__main__":
    root = tk.Tk()
    app = AppLivrosC(root)
    root.mainloop()