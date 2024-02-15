#include <stdio.h>
#include <elf.h>

/**
 * check_elf - Check if the file is ELF format
 * @e_ident: ELF identification bytes
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "This is not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Print ELF magic bytes
 * @e_ident: ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	printf("ELF Header:\n  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf(" %02x", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Print ELF class
 * @e_ident: ELF identification bytes
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("None\n");
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

/**
 * print_data - Print ELF data encoding
 * @e_ident: ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("None\n");
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

/**
 * print_version - Print ELF version
 * @e_ident: ELF identification bytes
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - Print ELF OS/ABI
 * @e_ident: ELF identification bytes
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
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
	case ELFOSABI_MODESTO:
		printf("Novell - Modesto\n");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD\n");
		break;
	case ELFOSABI_ARM_AEABI:
		printf("ARM - ARM EABI\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM - ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_abi - Print ABI Version
 * @e_ident: ELF identification bytes
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print ELF file type
 * @e_type: ELF file type
 */
void print_type(Elf64_Half e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
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

/**
 * print_entry - Print Entry point address
 * @e_entry: ELF entry point address
 */
void print_entry(Elf64_Addr e_entry)
{
	printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * close_elf - Close file
 * @fd: File descriptor
 */
void close_elf(int fd)
{
	close(fd);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;
	unsigned char *e_ident = elf_header.e_ident;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf-file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (EXIT_FAILURE);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		perror("read");
		close_elf(fd);
		return (EXIT_FAILURE);
	}

	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	print_abi(e_ident);
	print_type(elf_header.e_type);
	print_entry(elf_header.e_entry);

	close_elf(fd);
	return (EXIT_SUCCESS);
}

