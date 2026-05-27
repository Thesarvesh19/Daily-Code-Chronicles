func numberOfSpecialChars(word string) int {
    lower := map[rune]bool{}
    upper := map[rune]bool{}

    for _, ch := range word {
        if unicode.IsLower(ch) {
            lower[ch] = true
        } else {
            upper[unicode.ToLower(ch)] = true
        }
    }

    count := 0
    for ch := range lower {
        if upper[ch] {
            count++
        }
    }

    return count
}
