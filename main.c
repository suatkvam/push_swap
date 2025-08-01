#include "utils.h"
#include "error.h"
#include "error.h"
#include "utils.h" // ft_split'in bildirimi burada olmalı


// ... (main'in yardımcı fonksiyonları) ...

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **args;
    int     arg_count; // <-- Değişiklik yok

    if (argc < 2)
        return (0);

    // Argümanları hazırlama
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args) // ft_split malloc hatası verirse
            exit_error();

        // --- DÜZELTME: arg_count burada hesaplanmalı ---
        arg_count = 0;
        while (args[arg_count])
            arg_count++;
    }
    else
    {
        // argv + 1'i kullanırken const uyarısını şimdilik göz ardı et
        // veya explicit cast yap: args = (char **)(argv + 1);
        args = argv + 1;
        arg_count = argc - 1;
    }

    // validate_arguments artık her zaman başlatılmış bir arg_count alacak.
    validate_arguments(arg_count, args);

    // ... (kodun geri kalanı aynı) ...

    init_stack(&stack_a, arg_count);
    init_stack(&stack_b, arg_count);
    
    // ...
}