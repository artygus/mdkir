class Mdkir < Formula
  desc "Prints Kir if you type mdkir instead of mkdir"
  license "MIT"
  head "https://github.com/artygus/mdkir.git", branch: "main"

  uses_from_macos "ncurses"

  def install
    system "make", "-e"
    bin.install "mdkir"
  end
end
