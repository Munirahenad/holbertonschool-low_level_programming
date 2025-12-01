#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        break;
    }
}

void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
        break;
    }
}

void print_version(unsigned char *e_ident)
{
    printf("  Version:                           ");
    switch (e_ident[EI_VERSION])
    {
    case EV_NONE:
        printf("0 (invalid)\n");
        break;
    case EV_CURRENT:
        printf("1 (current)\n");
        break;
    default:
        printf("%d (unknown)\n", e_ident[EI_VERSION]);
        break;
    }
}

void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - GNU\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Stand-alone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
        break;
    }
}

void print_abiversion(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(uint16_t e_type)
{
    printf("  Type:                              ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
        break;
    }
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("0x%x\n", (unsigned int)e_entry);
    else
        printf("0x%lx\n", e_entry);
}

int main(int argc, char **argv)
{
    int fd;
    ssize_t read_bytes;
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    unsigned long int e_entry;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Cannot open file");

    /* قراءة Magic bytes أولاً لتحديد Class */
    read_bytes = read(fd, e_ident, EI_NIDENT);
    if (read_bytes != EI_NIDENT)
        print_error("Error: Cannot read ELF identification");

    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3)
        print_error("Error: Not an ELF file");

    /* الرجوع لبداية الملف */
    lseek(fd, 0, SEEK_SET);

    /* قراءة الرأس بناءً على Class */
    if (e_ident[EI_CLASS] == ELFCLASS32)
    {
        Elf32_Ehdr header32;
        
        read_bytes = read(fd, &header32, sizeof(header32));
        if (read_bytes != sizeof(header32))
            print_error("Error: Cannot read ELF header");
        
        e_type = header32.e_type;
        e_entry = header32.e_entry;
    }
    else if (e_ident[EI_CLASS] == ELFCLASS64)
    {
        Elf64_Ehdr header64;
        
        read_bytes = read(fd, &header64, sizeof(header64));
        if (read_bytes != sizeof(header64))
            print_error("Error: Cannot read ELF header");
        
        e_type = header64.e_type;
        e_entry = header64.e_entry;
    }
    else
    {
        print_error("Error: Unknown ELF class");
    }

    printf("ELF Header:\n");
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_osabi(e_ident);
    print_abiversion(e_ident);
    print_type(e_type);
    print_entry(e_entry, e_ident);

    if (close(fd) == -1)
        print_error("Error: Cannot close file descriptor");

    return (0);
}
