! Advent of Code 2015 : https://adventofcode.com/2015
! Puzzle for Day 01 part 01 :
! Build and run with Fortran Package Manager (fpm):
! fpm run aoc_day01_p1

program aoc_day01_p1

    use, intrinsic :: iso_fortran_env, stderr => error_unit
    implicit none

    ! Declare and set constants the AOC day and part
    integer, parameter :: day = 01, part = 1

    ! Declare file related variables
    ! - Prod uses: day01-input.txt
    ! - Test uses: day01-TEST-input.txt
    character(len = *), parameter :: filename = "data/day01-input.txt"

    ! Variables to track and manage the program
    integer :: floor_number = 0, up = 0, down = 0

    ! Output startup message
    call display_welcome(day, part)

    ! Check input puzzle data file and get its line count
    call get_floor(filename,floor_number,up,down)

    print *, ""
    write (*, '(A,I0)') "Floor changes analysed: ", (up + down)
    write (*, '(A,I0)') "Floors up are: ",up
    write (*, '(A,I0)') "Floors down are: ",down
    print *, ""
    write (*, '(A,I0)')  "PUZZLE ANSWER: Final floor is: ",floor_number
    print *, ""


contains

    ! Display the AoC puzzle day and part being resolved
    subroutine display_welcome(day, part)
        implicit none
        integer, intent(in) :: day, part
        print *, ""
        write (*, '(A,I2.2,A,I2.2)') "AoC 2015 - solution for Day ", day, " part ", part
        print *, ""
    end subroutine display_welcome

	! count the floor changes held in the single line of '(()()()" in the input file
	! where '(' is up one floor and ')' is down one floor 
    subroutine get_floor(filename,floor_number,up,down)
        implicit none
        character(len = *), intent(in) :: filename
        integer, intent(inout) :: floor_number, up, down
        integer :: fileunit, io
        logical :: exists
        character(len=1) :: next_floor

        inquire(file = filename, exist = exists)
        if (.not. exists) then
            ! below should be printed to stderr!!
            write (stderr, '(A,A)') "ERROR: unable to locate file name: ", filename
            return
        end if

        open(newunit = fileunit, file = filename, action = 'read', position = 'rewind')
        do
            read(fileunit,'(A)', iostat = io, advance='no') next_floor
            if (io /= 0) exit
            if (next_floor .eq. "(") then
                up = up + 1
            else
                down = down + 1
            end if
        end do

        floor_number = up - down

        close(fileunit)
    end subroutine get_floor

end program aoc_day01_p1
